## Catálogo Base

Por que escolher esta solução
- 100% SPA (sem recarregamento de página)
- Autossuficiente, não precisa de outra aplicação para fornecimento de dados
- **Não é uma loja online!** Apenas um catálogo online
- Interface Administrativa Intuitiva
- Autenticação **não persistente** com JWT (ao recarregar a página é necessário inserir email e senha novamente)
- Paginação dinâmica com base na tela do dispositivo

### Passo a Passo para o Desenvolvimento Local
1. No terminal, na pasta raiz, execute `yarn` para instalar as dependências
2. Após a instalação, execute `yarn regen` para iniciar o banco de dados local, além de gerar as tipagens dos dados para o TypeScript
3. Ao fim do passo anterior, execute `yarn dev`, e acesse o site em `localhost:3000`, você será redirecionado para a página de instalação do site, preencha com cuidado, pois ela só ocorre uma vez
