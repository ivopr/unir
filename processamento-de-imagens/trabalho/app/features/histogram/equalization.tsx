import { NativeStackScreenProps } from "@react-navigation/native-stack";
import { create } from "apisauce";
import {
  getMediaLibraryPermissionsAsync,
  launchImageLibraryAsync,
  MediaTypeOptions,
  requestMediaLibraryPermissionsAsync,
} from "expo-image-picker";
import FormData from "form-data";
import { FC, useEffect, useState } from "react";
import { Image } from "react-native";
import {
  Avatar,
  Button,
  H2,
  H4,
  Paragraph,
  Separator,
  XStack,
  YStack,
} from "tamagui";

export const EqualizationScreen: FC<
  NativeStackScreenProps<StackNavigatorParams, "equalization">
> = () => {
  const [selectedImage, setSelectedImage] = useState("");
  const [processedImage, setProcessedImage] = useState("");
  const [processing, setProcessing] = useState(false);

  const apisauce = create({
    baseURL: "https://procim-api.herokuapp.com",
    timeout: 300000,
    headers: {
      "Content-Type": "multipart/form-data",
    },
  });

  useEffect(() => {
    (async () => {
      const { status } = await getMediaLibraryPermissionsAsync();

      if (status !== "granted") {
        await requestMediaLibraryPermissionsAsync();
      }
    })();
  }, []);

  const process = async () => {
    setProcessing(true);
    const formdata = new FormData();

    formdata.append("file", {
      name: "image.jpg",
      uri: selectedImage,
      type: "image/jpeg",
    });

    await apisauce
      .post<string>("/equalization", formdata)
      .then(({ data }) => {
        if (data) {
          setProcessedImage(data as string);
        }
      })
      .catch(console.log)
      .finally(() => setProcessing(false));
  };

  const selectImage = async () => {
    setProcessedImage("");

    const response = await launchImageLibraryAsync({
      mediaTypes: MediaTypeOptions.Images,
    });

    if (response.cancelled === false) {
      setSelectedImage(response.uri);
    }
  };

  return (
    <YStack f={1} ai="center" p="$4" space>
      <YStack space="$2" maw={600}>
        <H2 ta="center">Processar Imagem</H2>
        <Paragraph ta="center">
          "Eu vou equalizar a tua cara" -Cassie Cage
        </Paragraph>
      </YStack>
      <Separator />
      <XStack space="$2">
        <Avatar size="$15">
          {selectedImage && selectedImage.length > 0 ? (
            <Avatar.Image
              defaultSource={0}
              src={selectedImage}
              w="100%"
              h="100%"
            />
          ) : null}
          <Avatar.Fallback />
        </Avatar>
        <YStack space jc="center">
          <Button
            disabled={processing ? true : undefined}
            onPress={selectImage}
            themeInverse
          >
            Selecionar Imagem
          </Button>
          <Button
            disabled={processing || !selectedImage ? true : undefined}
            onPress={process}
            themeInverse
          >
            Processar
          </Button>
        </YStack>
      </XStack>
      <Separator />
      <H4>Imagem Processada</H4>
      <Image
        source={{
          uri: `data:image/png;base64,${processedImage}`,
        }}
        style={{
          height: 200,
          width: 200,
        }}
      />
    </YStack>
  );
};
