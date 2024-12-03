# src/models/nlp_models.py

from pydantic import BaseModel
from typing import List, Optional

class PredictRequest(BaseModel):
    text: str  # The text you want to analyze

class PredictResponse(BaseModel):
    prediction: List[float]  # Example: Probability scores for each class

class TrainRequest(BaseModel):
    epochs: int  # Number of training epochs

class TrainResponse(BaseModel):
    message: str  # Confirmation message

class NERResponse(BaseModel):
    entities: List[dict]  # Named entities found

class SentimentResponse(BaseModel):
    sentiment: float  # Sentiment score

class POSTaggerResponse(BaseModel):
    pos_tags: List[dict]  # Part-of-speech tags
