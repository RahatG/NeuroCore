#include "DataLoader.h"
#include <arrow/api.h>
#include <arrow/io/api.h>
#include <parquet/arrow/reader.h>
#include <stdexcept>
#include <iostream>

DataLoader::DataLoader(const std::string& data_path) : data_path(data_path) {}

std::vector<std::string> DataLoader::load_data() {
    try {
        // Initialize Arrow's memory pool
        arrow::MemoryPool* pool = arrow::default_memory_pool();

        // Open the Parquet file
        std::shared_ptr<arrow::io::ReadableFile> infile;
        auto open_result = arrow::io::ReadableFile::Open(data_path, pool);
        if (!open_result.ok()) {
            std::cerr << "Failed to open data file at: " << data_path 
                      << "\nError: " << open_result.status().ToString() << std::endl;
            throw std::runtime_error("Failed to open data file.");
        }
        infile = *open_result;

        // Create Parquet reader
        std::unique_ptr<parquet::arrow::FileReader> reader;
        arrow::Status reader_result = parquet::arrow::OpenFile(infile, pool, &reader);
        if (!reader_result.ok()) {
            std::cerr << "Failed to create Parquet reader.\nError: " << reader_result.ToString() << std::endl;
            throw std::runtime_error("Failed to create Parquet reader.");
        }

        // Read the entire file into a table
        std::shared_ptr<arrow::Table> table;
        arrow::Status table_result = reader->ReadTable(&table);
        if (!table_result.ok()) {
            std::cerr << "Failed to read Parquet table.\nError: " << table_result.ToString() << std::endl;
            throw std::runtime_error("Failed to read Parquet table.");
        }

        // Extract data from the table
        std::vector<std::string> data;

        auto schema = table->schema();
        int num_columns = schema->num_fields();
        std::vector<std::string> column_names;
        for (int i = 0; i < num_columns; ++i) {
            column_names.emplace_back(schema->field(i)->name());
        }

        // Specify the target column
        std::string target_column = "markdown"; // Updated to match the Parquet schema
        int target_col_index = -1;
        for (int i = 0; i < num_columns; ++i) {
            if (column_names[i] == target_column) {
                target_col_index = i;
                break;
            }
        }

        if (target_col_index == -1) {
            std::cerr << "DataLoader Error: Target column '" << target_column << "' not found in Parquet file." << std::endl;
            std::cerr << "Available columns are:" << std::endl;
            for (const auto& col : column_names) {
                std::cerr << " - " << col << std::endl;
            }
            throw std::runtime_error("Target column not found in Parquet file.");
        }

        // Iterate through all chunks
        int num_chunks = table->column(target_col_index)->num_chunks();
        for (int chunk_index = 0; chunk_index < num_chunks; ++chunk_index) {
            auto chunk = table->column(target_col_index)->chunk(chunk_index);
            auto string_array = std::static_pointer_cast<arrow::StringArray>(chunk);

            int num_rows = string_array->length();
            for (int row = 0; row < num_rows; ++row) {
                if (!string_array->IsNull(row)) {
                    data.emplace_back(string_array->GetString(row));
                } else {
                    data.emplace_back("");
                }
            }
        }

        std::cout << "DataLoader: Successfully loaded " << data.size() << " entries." << std::endl;
        return data;
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "DataLoader Bad Allocation Error: " << e.what() << std::endl;
        throw;
    }
    catch (const std::exception& e) {
        std::cerr << "DataLoader Exception: " << e.what() << std::endl;
        throw;
    }
}
