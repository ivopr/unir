function y = teste
	clc;
	clearvars;

	v = load('teste.txt');
	[vLines, ~] = size(v);
	v = [-ones(vLines, 1) v];

	w = treinamento;
	
	for k = 1 : vLines
		x = v(k,:)';
		u = w' * x;
		if (u >= 0)
			y(k) = 1;
		else
			y(k) = -1;
		end
	end
end