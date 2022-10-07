import { useContext } from "react";

import { AppContext, AppContextKeys } from "./context";

export function useApp(): AppContextKeys {
  return useContext(AppContext);
}
