import bcrypt
import json
from random import randint
from email.mime.text import MIMEText
import smtplib

def sign_up(name, email, password, role):
  users = []
  try:
    with open("db.json", "r") as db:
      data = json.load(db)
        
    if(len(data) >= 1):
      for i in data:
        users.append(i)
  except:
    pass

  hashed_password = bcrypt.hashpw(bytes(password, encoding="utf-8"), bcrypt.gensalt())

  new_user_dict = {
    "name": name,
    "email" : email,
    "password" : bytes.decode(hashed_password),
    "role": role,
  }
  
  users.append(new_user_dict)
  
  with open("db.json", "w") as db:
    json.dump(users, db, indent=2)
  
  return True

def sign_in(email, password):
  users = []
  try:
    with open("db.json", "r") as db:
      data = json.load(db)
        
    if(len(data) >= 1):
      for i in data:
        users.append(i)
  except:
    print("Não há usuários cadastrados.")
    return False

  for j, user in enumerate(users):
    if user["email"] == email:
      if bcrypt.checkpw(bytes(password, encoding="utf-8"), bytes(user["password"], encoding="utf-8")):
        verificationCode = randint(100000, 999999)

        msg = MIMEText(f"<h3>Seu codigo é: {verificationCode}</h3>",'html', 'utf-8')

        #Criar email da oficial para o sistema
        msg['From'] = 'Segurança da Informação'
        msg['To'] = email
        msg['Subject'] = 'Seu Código - SegInfo'
        message = msg.as_string()
        server = smtplib.SMTP_SSL('smtp.gmail.com', 465)
        server.login("email+enviador@gmail.com", "app_password")
        server.sendmail("email+enviador@gmail.com", email, message)
        server.quit()

        userInputCode = input("Digite o código enviado para o seu email: ")

        if (verificationCode == int(userInputCode)):
          print("Código validado! Efetuando Login")
          print(f"Bem vindo(a) de volta {user['name']} ({user['role'].upper()})")
        else:
          print("Código não confere.")
      else:
        print("Email ou senha incorretos.")
        return
    if j == len(users):
      print("Usuário não encontrado.")
      return

  return True

if __name__ ==  "__main__":
  opcao = 0
  while(int(opcao) >= 0 and int(opcao) <= 2):
    print("1 - Cadastrar \n2 - Entrar\n0 - Exibir esse menu novamente\nN - Sair")
    opcao = input("Escolha uma opção: ")

    if opcao == "1":
      name = input("Nome: ")
      email = input("Email: ")
      role = input("Cargo (Admin / User): ")
      password = input("Senha: ")
      
      if sign_up(name, email, password, role):
        print("Usuário Cadastrado.")
      else:
        print("Usuário NÃO Cadastrado.")
        
    elif opcao == "2":
      email = input("Email: ")
      password = input("Senha: ")

      sign_in(email, password)
