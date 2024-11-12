from ..interface.InterfaceEngine import InterfaceEngine

class Processor:
    def __init__(self, data_path, model_output_path):
        self.engine = InterfaceEngine(data_path, model_output_path)

    def process(self, text):
        return self.engine.predict(text)
