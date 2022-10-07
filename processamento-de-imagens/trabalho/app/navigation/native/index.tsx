import { createNativeStackNavigator } from "@react-navigation/native-stack";
import { FC } from "react";

import { EqualizationScreen } from "../../features/histogram/equalization";
import { ExpansionScreen } from "../../features/histogram/expansion";
import { HomeScreen } from "../../features/home/screen";
import { MeanScreen } from "../../features/mean";
import { MedianScreen } from "../../features/median";
import { NegativeScreen } from "../../features/negative";
import { FromYIQScreen } from "../../features/rgb-yiq/from";
import { ToYIQScreen } from "../../features/rgb-yiq/to";
import { SobelScreen } from "../../features/sobel";
import { Header } from "../header";

const Stack = createNativeStackNavigator<StackNavigatorParams>();

export const NativeNavigation: FC = () => {
  return (
    <Stack.Navigator
      screenOptions={{
        header: ({ route: { name } }) => (
          <Header name={name as keyof StackNavigatorParams} />
        ),
      }}
    >
      <Stack.Screen name="home" component={HomeScreen} />
      <Stack.Screen name="toyiq" component={ToYIQScreen} />
      <Stack.Screen name="fromyiq" component={FromYIQScreen} />
      <Stack.Screen name="equalization" component={EqualizationScreen} />
      <Stack.Screen name="expansion" component={ExpansionScreen} />
      <Stack.Screen name="negative" component={NegativeScreen} />
      <Stack.Screen name="sobel" component={SobelScreen} />
      <Stack.Screen name="mean" component={MeanScreen} />
      <Stack.Screen name="median" component={MedianScreen} />
    </Stack.Navigator>
  );
};
