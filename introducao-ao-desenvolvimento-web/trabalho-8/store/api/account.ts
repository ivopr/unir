import { User } from "@prisma/client";
import { createApi, fetchBaseQuery } from "@reduxjs/toolkit/query/react";

// Define a service using a base URL and expected endpoints
export const accountApi = createApi({
  reducerPath: "accountApi",
  baseQuery: fetchBaseQuery({
    baseUrl: `/api/account/`,
  }),
  refetchOnFocus: true,
  refetchOnMountOrArgChange: true,
  endpoints: (builder) => ({
    getAllAccounts: builder.query<User[], null>({
      query: () => ({ url: "read" }),
    }),
    postCreateAccount: builder.mutation<
      User,
      {
        email: string;
        name: string;
        password: string;
        role: string;
        roleGuard?: string;
        cnpj?: string;
        address?: string;
        phone?: string;
      }
    >({
      query: (body) => ({ url: "create", body, method: "POST" }),
    }),
    deleteAccount: builder.mutation<{ message: string }, string>({
      query: (accountId) => ({ url: `delete?accountId=${accountId}`, method: "DELETE" }),
    }),
    toggleAccountActive: builder.mutation<{ message: string }, string>({
      query: (accountId) => ({ url: `toggle-active?accountId=${accountId}`, method: "POST" }),
    }),
    putUpdateAccount: builder.mutation<
      User,
      {
        id: string;
        name: string;
        email: string;
        role: string;
        cnpj?: string;
        address?: string;
        phone?: string;
      }
    >({
      query: (body) => ({ url: `update?userId=${body.id}`, body, method: "PUT" }),
    }),
  }),
});

// Export hooks for usage in functional components, which are
// auto-generated based on the defined endpoints
export const {
  useGetAllAccountsQuery,
  usePostCreateAccountMutation,
  useDeleteAccountMutation,
  useToggleAccountActiveMutation,
  usePutUpdateAccountMutation,
} = accountApi;
