from ..models.user_models import User, UserCreate, UserUpdate
from typing import List

class UserService:
    def __init__(self):
        self.users = {}

    def create_user(self, user: UserCreate):
        if user.username in self.users:
            raise Exception("User already exists.")
        self.users[user.username] = user.password

    def authenticate_user(self, username: str, password: str) -> bool:
        return self.users.get(username) == password

    def update_user(self, username: str, user: UserUpdate):
        if username not in self.users:
            raise Exception("User does not exist.")
        self.users[username] = user.password
