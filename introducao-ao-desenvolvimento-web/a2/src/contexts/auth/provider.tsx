import React, { ReactNode, useState } from "react";

import { AuthContext, AuthKeys } from "./context";

type AuthProviderProps = {
  children: ReactNode;
};

export function AuthProvider({ children }: AuthProviderProps): JSX.Element {
  const [auth, setAuth] = useState({} as AuthKeys);

  return (
    <AuthContext.Provider value={{ auth, setAuth }}>
      {children}
    </AuthContext.Provider>
  );
}
