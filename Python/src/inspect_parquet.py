# inspect_parquet.py

import pyarrow.parquet as pq

def inspect_parquet(file_path):
    try:
        table = pq.read_table(file_path)
        print("Parquet File Schema:")
        print(table.schema)
        print("\nColumn Names:")
        for column in table.schema.names:
            print(f"- {column}")
    except Exception as e:
        print(f"Failed to read Parquet file: {e}")

if __name__ == "__main__":
    parquet_file = "/home/rahat/arxiver/data/train.parquet"  # Update this path if different
    inspect_parquet(parquet_file)
