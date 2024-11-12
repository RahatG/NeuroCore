from pydantic import BaseModel
from typing import List

class NERResponse(BaseModel):
    entities: List[dict]

class SentimentResponse(BaseModel):
    sentiment: float

class POSTaggerResponse(BaseModel):
    pos_tags: List[dict]
    