import { useNavigation } from "@react-navigation/native";
import { ArrowLeftCircle } from "@tamagui/feather-icons";
import { FC } from "react";
import { Button, H2, XStack } from "tamagui";

type HeaderProps = {
  name: keyof StackNavigatorParams;
};

export const Header: FC<HeaderProps> = ({ name }) => {
  const { canGoBack, goBack } = useNavigation();

  return (
    <XStack ai="center" h="$5" px="$2.5" space="$2.5">
      {canGoBack() ? <Button icon={ArrowLeftCircle} onPress={goBack} /> : null}
      <H2 textTransform="capitalize">{name}</H2>
    </XStack>
  );
};
