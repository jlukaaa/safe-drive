
import pytest
import math

def zbir(brojevi : list) -> int:
    return sum(brojevi)

def proizvod(brojevi : list) -> int:
    return math.prod(brojevi)

@pytest.fixture
def lista_brojeva():
    return [2, 3, 4]


def test_zbir(lista_brojeva):
    rez = zbir(lista_brojeva)
    assert rez == 9

def test_proizvod(lista_brojeva):
    rez = proizvod(lista_brojeva)
    assert rez == 24

