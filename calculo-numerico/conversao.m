function x = decTobin(n)
  % Parte inteira do decimal para binario
  x = [];
  while(n > 0)
    r = mod(n,2);
    n = fix(n/2);
    x(end + 1) = r;
  end
  x = x(end:-1:1);
end

function x = decTooct(n)
  % Parte inteira do decimal para octal
  x = [];
  while(n > 0)
    r = mod(n,8);
    n = fix(n/8);
    x(end + 1) = r;
  end
  x = x(end:-1:1);
end

function x = fracTobin(n)
  % Parte decimal para binario
  x = [];
  r = n;
  while(r > 0)
    if(2 * r >= 1)
      x(end + 1) = 1;
    else
      x(end + 1) = 0;
    end

    r = 2 * r - x(end);
    if(r == 0)
      break
    end
  end
end

function n = binTofrac(x)
  % Parte fracionária do binário para decimal
  n = 0;
  x = x(end:-1:1);
  for i=1:length(x)
    n = 1/2 * (str2num(x(i)) + n);
  end
end

function n = binTodec(x)
  n = 0;
  x = x(end:-1:1);
  for i=1:length(x)
    print(x);
    n += str2num(x(i)) * 2^(i-1);
  end
end
