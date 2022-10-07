import { createContext } from "react";

export type ConfigKeys = {
  appName: string;
};

export type AppContextKeys = {
  config: ConfigKeys;
  loadConfig: () => Promise<void>;
};

export const AppContext = createContext({} as AppContextKeys);
