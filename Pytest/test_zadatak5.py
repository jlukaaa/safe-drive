import pytest
from unittest.mock import Mock
class DatabaseService:
        def get_user(self, user_id):
            #U stvarnosti bi citao iz baze
            pass

        def save_user(self, user_id, data):
            #U stvarnosti i upisivao u bazu
            pass

        def get_user_info(service, user_id):
            user = service.get_user(user_id)
            if user:
                return f"Korisnik: {user_id}, Podaci: {user}"
            return "Korisnik nije pronadjen"
        
        def register_user(service, user_id, data):
            service.save_user(user_id, data)
            return f"Korisnik: {user_id} uspjesno registrovan!"
        
@pytest.fixture
def mock_service():
     return Mock(spec = DatabaseService)

def test_get_user_info_when_user_exists(mock_service):
     user_id = 101
     mock_data = {"ime" : "Ana", "uloga" : "admin"}

     mock_service.get_user.return_value = mock_data

     rez = DatabaseService.get_user_info(mock_service, user_id)

     expected_rez = f"Korisnik: {user_id}, Podaci: {mock_data}"
     assert rez == expected_rez;

     mock_service.get_user.assert_called_once_with(user_id)

def test_get_user_info_when_user_doesnt_exist(mock_service):
     
     user_id = 999

     mock_service.get_user.return_value = None

     rez = DatabaseService.get_user_info(mock_service, user_id)

     assert rez == "Korisnik nije pronadjen"

     mock_service.get_user.assert_called_once_with(user_id)

def test_register_user_save_with_corr_arg(mock_service):
     
     user_id = 55
     user_data = {"email": "marko@example.com", "grad" : "BanjaLuka"}

     rez = DatabaseService.register_user(mock_service,user_id, user_data)

     mock_service.save_user.assert_called_once_with(user_id, user_data)

     assert rez == f"Korisnik: {user_id} uspjesno registrovan!"

     