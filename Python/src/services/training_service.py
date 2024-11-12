from ..interface.InterfaceEngine import InterfaceEngine
from ..config.settings import settings

class TrainingService:
    def __init__(self):
        self.engine = InterfaceEngine(settings.data_path, settings.model_output_path)

    def train(self, epochs):
        self.engine.train(epochs)
