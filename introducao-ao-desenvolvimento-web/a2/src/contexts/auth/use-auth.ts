import { useContext } from "react";

import { AuthContext, AuthContextKeys } from "./context";

export function useAuth(): AuthContextKeys {
  return useContext(AuthContext);
}
