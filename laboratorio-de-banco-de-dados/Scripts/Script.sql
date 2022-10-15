-- SELECT c.nome, v.id_veiculo FROM estacionamento.cliente c, estacionamento.veiculo v WHERE v.marca = 'fiat' AND v.id_cliente = c.id_cliente;

-- SELECT c.nome, v.placa, v.marca FROM estacionamento.cliente c, estacionamento.veiculo v WHERE v.marca = 'fiat' AND v.id_cliente = c.id_cliente;

SELECT c.nome, v.placa, v.marca, v.modelo FROM estacionamento.cliente c JOIN estacionamento.veiculo v ON c.id_cliente = v.id_cliente WHERE v.modelo = 'siena'; 