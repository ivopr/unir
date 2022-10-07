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
      { email: string; name: string; password: string; role: string; roleGuard?: string }
    >({
      query: (body) => ({ url: "create", body, method: "POST" }),
    }),
  }),
});

// Export hooks for usage in functional components, which are
// auto-generated based on the defined endpoints
export const { useGetAllAccountsQuery, usePostCreateAccountMutation } = accountApi;
