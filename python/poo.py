class Pessoa:
  # metodo construtor
  def __init__(self, nome, idade):
    self.nome = nome
    self.idade = idade
    self.pais = "Brasil"
    
  def __str__(self):
    return f'Nome: {self.nome} , Idade: {self.idade}'

joao = Pessoa("Joao da Silva", 23)
maria = Pessoa("Maria da Silva", 25)

print(joao)
print(maria)