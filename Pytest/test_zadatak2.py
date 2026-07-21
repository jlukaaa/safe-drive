import pytest

def je_palindrom(s: str) -> bool:
    if not isinstance(s, str):
        raise TypeError("Pogresan tip podatka!")
    
    cist_string = s.lower().replace(" ", "")

    return cist_string == cist_string[::-1]

@pytest.mark.parametrize("ulaz,ocekivano", [

    ("ana", True),
    ("radar", True),
    ("Python", False),
    ("Ana", True),
    ("A N A", True)
])

def test_je_palindrom(ulaz, ocekivano):
    assert je_palindrom(ulaz) == ocekivano

def test_pograsan_tip():
    with pytest.raises(TypeError) as exc_info:
        je_palindrom(21414)


