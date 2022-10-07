import axios, { AxiosInstance } from "axios";
import { GetServerSidePropsContext } from "next";

export function setupApiClient(
  context?: GetServerSidePropsContext
): AxiosInstance {
  let baseURL;

  if (context) {
    const { req } = context;
    // Server side rendering
    baseURL = "http://" + req.headers.host + "/api";
  } else {
    // Client side rendering
    baseURL =
      window.location.protocol +
      "//" +
      window.location.hostname +
      (window.location.port ? ":" + window.location.port : "") +
      "/api";
  }

  return axios.create({
    baseURL,
  });
}
