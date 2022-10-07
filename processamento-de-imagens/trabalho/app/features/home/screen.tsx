import { NativeStackScreenProps } from "@react-navigation/native-stack";
import {
  getMediaLibraryPermissionsAsync,
  requestMediaLibraryPermissionsAsync,
} from "expo-image-picker";
import { FC, useEffect } from "react";
import { Button, H2, Paragraph, Separator, YStack } from "tamagui";

export const HomeScreen: FC<
  NativeStackScreenProps<StackNavigatorParams, "home">
> = ({ navigation }) => {
  useEffect(() => {
    (async () => {
      const { status } = await getMediaLibraryPermissionsAsync();

      if (status !== "granted") {
        await requestMediaLibraryPermissionsAsync();
      }
    })();
  }, []);

  return (
    <YStack f={1} ai="center" p="$4" space>
      <YStack space="$2" maw={600}>
        <H2 ta="center">Processador de Imagens Philips Wallita</H2>
        <Paragraph ta="center">
          Escolha o tipo de processamento abaixo
        </Paragraph>
      </YStack>
      <Separator />
      <YStack>
        <Button onPress={() => navigation.navigate("toyiq")} themeInverse>
          RGB para YIQ
        </Button>

        <Button onPress={() => navigation.navigate("fromyiq")} themeInverse>
          YIQ para RGB
        </Button>

        <Button onPress={() => navigation.navigate("negative")} themeInverse>
          Negativo
        </Button>

        <Button onPress={() => navigation.navigate("expansion")} themeInverse>
          Expansão de Histograma
        </Button>

        <Button
          onPress={() => navigation.navigate("equalization")}
          themeInverse
        >
          Equalização de Histograma
        </Button>

        <Button onPress={() => navigation.navigate("sobel")} themeInverse>
          Gradiente de Sobel
        </Button>

        <Button onPress={() => navigation.navigate("mean")} themeInverse>
          Filtro de Média
        </Button>

        <Button onPress={() => navigation.navigate("median")} themeInverse>
          Filtro de Mediana
        </Button>
      </YStack>
    </YStack>
  );
};
