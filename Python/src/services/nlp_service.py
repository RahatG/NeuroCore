from ..nlp.processor import Processor
from ..config.settings import settings

class NLPService:
    def __init__(self):
        self.processor = Processor(settings.data_path, settings.model_output_path)

    def perform_ner(self, tokens):
        return self.processor.engine.ner_recognize(tokens)

    def perform_sentiment_analysis(self, tokens):
        return self.processor.engine.sentiment_analyze(tokens)

    def perform_pos_tagging(self, tokens):
        return self.processor.engine.pos_tag(tokens)
