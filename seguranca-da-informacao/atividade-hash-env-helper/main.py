import bcrypt
import json
import subprocess
import os

def add_or_create(environment_name, environment_password, var_name, var_value):
  os.system("clear")
  environments = {}
  try:
    with open("db.json", "r") as db:
      environments = json.load(db)
  except:
    pass

  if environment_name in environments:
    # get eisting env dict
    environment_dict = environments[environment_name]
    
    if bcrypt.checkpw(bytes(environment_password, encoding="utf-8"), bytes(environment_dict["password"], encoding="utf-8")):
      # get existing env vars
      environment_vars = environment_dict["vars"]

      # add/modify new var to existing vars
      environment_vars[var_name] = var_value
      
      # replace old vars with new ones
      environment_dict["vars"] = environment_vars
    else:
      return False
  else:
    hashed_password = bcrypt.hashpw(bytes(environment_password, encoding="utf-8"), bcrypt.gensalt())

    environment_dict = {
      "password": bytes.decode(hashed_password),
      "vars": {
        var_name: var_value
      }
    }
    
  environments[environment_name] = environment_dict
  
  with open("db.json", "w") as db:
    json.dump(environments, db, indent=2)
  
  return True

def apply_environment(environment_name, environment_password):
  environments = {}
  try:
    with open("db.json", "r") as db:
      environments = json.load(db)
  except:
    pass

  if environment_name in environments:
    environment_dict = environments[environment_name]

    if bcrypt.checkpw(bytes(environment_password, encoding="utf-8"), bytes(environment_dict["password"], encoding="utf-8")):
      os.system("clear")
      for var_name in environment_dict["vars"]:
        var_value = environment_dict["vars"][var_name]

        print(f"you should run: export {var_name.upper()}=\"{var_value}\"")
      print("\n")

if __name__ ==  "__main__":
  opcao = 0
  while(int(opcao) >= 0 and int(opcao) <= 2):
    print("1 - Adicionar Variável/Ambiente\n2 - Aplicar Ambiente\n0 - Exibir esse menu novamente\nN - Sair")
    opcao = input("Escolha uma opção: ")

    if opcao == "1":
      environment_name = input("Nome do Ambiente: ")
      environment_password = input("Senha do Ambiente: ")
      var_name = input("Nome da Variável: ")
      var_value = input("Valor da Variável: ")
      
      if add_or_create(environment_name, environment_password, var_name, var_value):
        print("Variável Adicionada.")
      else:
        print("Variável NÃO Adicionada.")
      print("\n")
        
    elif opcao == "2":
      environment_name = input("Nome do Ambiente: ")
      environment_password = input("Senha do Ambiente: ")

      apply_environment(environment_name, environment_password)
