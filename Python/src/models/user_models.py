# src/models/user_models.py

from pydantic import BaseModel
from typing import List, Optional

# User-related Pydantic Models

class UserBase(BaseModel):
    username: str

class UserCreate(UserBase):
    password: str

class UserUpdate(UserBase):
    password: Optional[str] = None  # Allow password updates

class UserInDB(UserBase):
    id: int
    hashed_password: str

    model_config = {
        "from_attributes": True
    }

# NLP-related Pydantic Models (Consider moving these to nlp_models.py for clarity)

class PredictRequest(BaseModel):
    text: str

class PredictResponse(BaseModel):
    prediction: List[float]

class TrainRequest(BaseModel):
    epochs: int

class TrainResponse(BaseModel):
    message: str

class NERResponse(BaseModel):
    entities: List[dict]

class SentimentResponse(BaseModel):
    sentiment: float

class POSTaggerResponse(BaseModel):
    pos_tags: List[dict]
