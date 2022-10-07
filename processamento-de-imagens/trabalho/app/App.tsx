import "expo-dev-client";

import { useFonts } from "expo-font";
import { FC } from "react";
import { SafeAreaProvider, SafeAreaView } from "react-native-safe-area-context";

import { NativeNavigation } from "./navigation/native";
import { Provider } from "./provider";

const App: FC = () => {
  const [loaded] = useFonts({
    Inter: require("@tamagui/font-inter/ttf/Inter.ttf"),
  });

  if (!loaded) {
    return null;
  }

  return (
    <SafeAreaProvider style={{ flex: 1 }}>
      <SafeAreaView>
        <Provider>
          <NativeNavigation />
        </Provider>
      </SafeAreaView>
    </SafeAreaProvider>
  );
};

export default App;
