import { Product } from "@prisma/client";
import { createApi, fetchBaseQuery } from "@reduxjs/toolkit/query/react";

// Define a service using a base URL and expected endpoints
export const productApi = createApi({
  reducerPath: "productApi",
  baseQuery: fetchBaseQuery({
    baseUrl: `/api/product/`,
  }),
  refetchOnFocus: true,
  refetchOnMountOrArgChange: true,
  endpoints: (builder) => ({
    getAllProducts: builder.query<Product[], null>({
      query: () => ({ url: "read" }),
    }),
    getMyProducts: builder.query<Product[], string>({
      query: (email) => ({ url: `read?email=${email}` }),
    }),
    deleteProduct: builder.mutation<{ message: string }, string>({
      query: (productId) => ({ url: `delete?productId=${productId}`, method: "DELETE" }),
    }),
    putUpdateProduct: builder.mutation<
      Product,
      {
        id: string;
        quantity?: number;
        name: string;
        price: number;
        type?: string;
      }
    >({
      query: (body) => ({ url: `update?productId=${body.id}`, body, method: "PUT" }),
    }),
    postCreateProduct: builder.mutation<
      Product,
      {
        quantity?: number;
        name: string;
        price: number;
        type?: string;
      }
    >({
      query: (body) => ({ url: "create", body, method: "POST" }),
    }),
  }),
});

// Export hooks for usage in functional components, which are
// auto-generated based on the defined endpoints
export const {
  useGetAllProductsQuery,
  useGetMyProductsQuery,
  usePutUpdateProductMutation,
  useDeleteProductMutation,
  usePostCreateProductMutation,
} = productApi;
