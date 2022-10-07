% ATIVIDADE 1 - 5

function [img] = r2h(image)
  pkg load image;

  image = im2double(image);

  imageR = image(:, :, 1);
  imageG = image(:, :, 2);
  imageB = image(:, :, 3);

  num = 0.5 * ((imageR - imageG) + (imageR - imageB));
  den =  power(power((imageR - imageG), 2) + (imageR - imageB) * (imageG - imageB), 0.5);

  H = acosd(num ./ den);

  H(imageB > imageG) = 360 - H(imageB > imageG);

  H = H/360;

  S = 1 - (3 ./ sum(image, 3)) .* min(image, [], 3);

  I = 1 / 3 * sum(image, 3);


  img = zeros(size(image));
  img(:, :, 1) = H;
  img(:, :, 2) = S;
  img(:, :, 3) = I;

  % Na conversão manual, a imagem resultado 'img' apresenta uma tonalidade mais
  % escura em comparação com o resultado obtido através da função 'rgb2hsi'
  imshow([img rgb2hsv(image)]);
endfunction
