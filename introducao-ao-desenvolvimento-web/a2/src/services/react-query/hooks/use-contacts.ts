import { Contact } from "@prisma/client";
import { GetServerSidePropsContext } from "next";
import { useQuery, UseQueryOptions, UseQueryResult } from "react-query";

import { setupApiClient } from "../../api";

export interface GetContactsResponse {
  contacts: Contact[];
  total: number;
}

export async function getContacts(
  page = 1,
  skip = 10,
  context?: GetServerSidePropsContext
): Promise<GetContactsResponse> {
  const api = setupApiClient(context);
  const { data } = await api.get(`/contacts?page=${page}&skip=${skip}`);

  const contacts: Contact[] = data.contacts;
  const total = data.totalContacts;

  return { contacts, total };
}

export function useContactsQuery(
  page = 1,
  skip = 10,
  options?: UseQueryOptions<GetContactsResponse>
): UseQueryResult<GetContactsResponse> {
  return useQuery<GetContactsResponse>(
    ["contacts", page, skip],
    () => getContacts(page, skip),
    {
      staleTime: 1000 * 60 * 10,
      ...options,
    }
  );
}
