% abrir imagem
img = imread("images/lena512color.tiff");

% separar os canais de cor da imagem
% 1- vermelho
% 2- verde
% 3- azul

lenaRed = img(:, :, 1);
lenaGreen = img(:, :, 2);
lenaBlue = img(:, :, 3);

figure, imshow([lenaRed lenaGreen lenaBlue]);
title("componentes de cor");

% iniciar uma matriz com 3 canais
lenaR = lenaG = lenaB = zeros(size(img));

% definir o canal vermelho da nova matriz como sendo o canal
% vermelho extraido da imagem
lenaR(:, :, 1) = lenaRed;
lenaR(:, :, 2) = 0;
lenaR(:, :, 3) = 0;

lenaG(:, :, 1) = 0;
lenaG(:, :, 2) = lenaGreen;
lenaG(:, :, 3) = 0;

lenaB(:, :, 1) = 0;
lenaB(:, :, 2) = 0;
lenaB(:, :, 3) = lenaBlue;

% exibe a imagem nova, apenas com o canal vermelho
figure, imshow([lenaR/255 lenaG/255 lenaB/255]);
title("canais de cores separados");

figure, imshow(lenaR/255 + lenaG/255 + lenaB/255);
title("imagem refeita");
