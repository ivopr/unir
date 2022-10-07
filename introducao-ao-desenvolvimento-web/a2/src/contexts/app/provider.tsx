import React, { ReactNode, useEffect, useState } from "react";

import { setupApiClient } from "../../services/api";
import { AppContext, ConfigKeys } from "./context";

type AppProviderProps = {
  children: ReactNode;
};

export function AppProvider({ children }: AppProviderProps): JSX.Element {
  const [config, setConfig] = useState({} as ConfigKeys);

  useEffect(() => {
    loadConfig();
  }, []);

  async function loadConfig(): Promise<void> {
    const api = setupApiClient();

    api.get("/config").then(({ data }) => {
      if (data.message && data.message === "config.notFound") {
        // DO NOTHING
      } else {
        setConfig(data as ConfigKeys);
      }
    });
  }

  return (
    <AppContext.Provider
      value={{
        config,
        loadConfig,
      }}
    >
      {children}
    </AppContext.Provider>
  );
}
