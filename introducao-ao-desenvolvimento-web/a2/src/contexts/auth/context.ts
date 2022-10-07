import { Users } from "@prisma/client";
import { createContext } from "react";

export type AuthKeys = {
  token: string;
  user: Pick<Users, "name" | "email" | "createdAt">;
};

export type AuthContextKeys = {
  auth: AuthKeys;
  setAuth: (auth: AuthKeys) => void;
};

export const AuthContext = createContext({} as AuthContextKeys);
