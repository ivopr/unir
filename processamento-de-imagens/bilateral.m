pkg image load

# 1: Original
img = imread('images/arabic.png');
img1 = rgb2gray(img);
#subplot(3, 2, 1); imshow(img1); title("Imagem 1");

# 2: Imagem 1 binarizada
img2 = im2bw(img1);
#subplot(3, 2, 2); imshow(img2); title("Imagem 2");

# 3: Imagem 1 com filtro bilateral
img3 = imsmooth(img1, 'Bilateral');
#subplot(3, 2, 3); imshow(img3); title("Imagem 3");

# Interlude: Modificações pelo caminho
disk = strel('disk', 2, 0);
img3 = imdilate(imerode(img3, disk), disk);
img3 = imdilate(imerode(img3, disk), disk);
img3 = imerode(imdilate(img3, disk), disk);

# 4: Imagem 3 com filtro Gaussiano para remoção de fundo
mask = fspecial('gaussian', 50, 30);
blur = imfilter(img3, mask);
blurred = img3 - blur;
img4 = img3 + blurred;
#subplot(3, 2, 4); imshow(img4); title("Imagem 4");

# 5: Subtrai imagem borrada da imagem filtrada
img5 = (img3 - img4) + img3;
#subplot(3, 2, 5); imshow(img5); title("Imagem 5");

# 6: Diltação Morfológica
img6 = img5;

# 7: Limiarização Global
T = mean2(img6);
done = false;

while(~done)
  g = img6 > T;
  Tnext = 0.5 * (mean(img6(g)) + mean(img6(~g)));
  done = abs(T - Tnext) < 0.5;
  T = Tnext;
endwhile

img6(img6 > T) = 255;
img6(img6 <= T) = 0;

#subplot(3, 2, 6);
figure, imshow(img6);
#title("Imagem 6");
figure, imshow(img5);
figure, imshow(img4);
figure, imshow(img3);
figure, imshow(img2);
figure, imshow(img1);
