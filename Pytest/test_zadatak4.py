import pytest

class UserSystem:
    def __init__(self):
        self.users = {}

    def add_users(self, username, email):
        if username in self.users:
            raise ValueError("Korisnik vec postoji")
        self.users[username] = email

    def get_email(self, username):
        return self.users.get(username)
    
@pytest.fixture
def empty_system():
    return UserSystem()

@pytest.fixture
def p_s(empty_system):
    empty_system.add_users("ana", "ana@example.com")
    empty_system.add_users("marko", "marko@example.com")
    return empty_system
    
@pytest.mark.parametrize("username, email", [
    ("stefan", "stefan@example.com"),
    ("milica", "milica@example.com"),
    ("user111", "user@example.com"),
])

def test_add_and_get_email_success(empty_system, username, email):
    empty_system.add_users(username, email)
    assert empty_system.get_email(username) == email

@pytest.mark.parametrize("non_existent_user", [
    "nepoznati_user",
    "admin",
    "petar",
])
def test_get_email_returns_none_for_missing_user(p_s, non_existent_user):
    assert p_s.get_email(non_existent_user) is None

@pytest.mark.parametrize("existing_username, new_email", [
   ("ana", "nova_ana@example.com"),
   ("marko", "novi_marko@example.com"),
])

def test_add_existing_user_raises_value_error(p_s, existing_username, new_email):
    with pytest.raises(ValueError, match = "Korisnik vec postoji"):
        p_s.add_users(existing_username, new_email)