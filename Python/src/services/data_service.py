from InterfaceEngine import DataLoader

class DataService:
    def __init__(self, data_path):
        self.loader = DataLoader(data_path)

    def get_data(self):
        return self.loader.load_data()
