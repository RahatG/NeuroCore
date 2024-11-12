from pydantic import BaseModel

class User(BaseModel):
    username: str

class UserCreate(BaseModel):
    username: str
    password: str

class UserUpdate(BaseModel):
    password: str
