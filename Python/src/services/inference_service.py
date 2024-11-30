from ..nlp.processor import Processor
from ..config.settings import settings

class InferenceService:
    def __init__(self):
        self.processor = Processor(settings.data_path, settings.model_output_path)

    def predict(self, text):
        return self.processor.process(text)
