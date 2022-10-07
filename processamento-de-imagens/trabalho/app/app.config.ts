import { ConfigContext, ExpoConfig } from "@expo/config";
const IS_DEV = process.env.APP_VARIANT === "development";
const IS_BETA = process.env.APP_VARIANT === "beta";

export default ({ config }: ConfigContext): ExpoConfig => ({
  ...config,
  assetBundlePatterns: ["**/*"],
  scheme: "procim",
  name: IS_DEV ? "[DEV] PdI" : IS_BETA ? "PdI Beta" : "PdI",
  slug: "pdi",
  version: "1.0.0",
  orientation: "portrait",
  icon: IS_DEV
    ? "./assets/icons/icon-dev.png"
    : IS_BETA
    ? "./assets/icons/icon-beta.png"
    : "./assets/icons/icon.png",
  userInterfaceStyle: "light",
  splash: {
    backgroundColor: "#ddffe2",
    image: "./assets/splash.png",
    resizeMode: "contain",
  },
  updates: {
    fallbackToCacheTimeout: 0,
  },
  android: {
    package: IS_DEV ? "com.demonicat.pdi.devclient" : "com.demonicat.pdi",
    versionCode: 2,
  },
  androidNavigationBar: {
    backgroundColor: "#ddffe2",
    barStyle: "dark-content",
  },
  androidStatusBar: {
    backgroundColor: "#ddffe2",
    barStyle: "dark-content",
  },
  plugins: ["expo-image-picker"],
});
