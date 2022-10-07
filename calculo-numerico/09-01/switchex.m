idade_usuario = input('Digite sua idade: ');

switch(idade_usuario)
	case num2cell([18:21])
		disp('Usuário no Grupo 1');
	case num2cell([22:30])
		disp('Usuário no Grupo 2');
	case num2cell([31:40])
		disp('Usuário no Grupo 3');
	case num2cell([41:50])
		disp('Usuário no Grupo 4');
	case num2cell([51:60])
		disp('Usuário no Grupo 5');
	otherwise
		disp('Usuário não cumpre requerimentos. Envelheça/Rejuveneça');
endswitch
