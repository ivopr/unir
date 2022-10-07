function z = EQM(T, w, d)
	s = 0;
	
	p = size(T,1);
	
	for k = 1 : p
		x = T(k,:)';
		u = w' * x;
		s = s + (d(k) - u)^2;
	end
	
	z = (1 / p) * s;
end