# src/init_db.py

from sqlalchemy.orm import Session
from .database import engine, Base
from .models.user import User

def init_db():
    Base.metadata.create_all(bind=engine)
    print("Database tables created successfully.")

if __name__ == "__main__":
    init_db()
