open Lwt;
open Cohttp;
open Cohttp_lwt_unix;

let print_request = (uri, meth, headers, body) => {
      Printf.sprintf(
        "Uri: %s\nMethod: %s\nHeaders\nHeaders: %s\nBody: %s",
        uri,
        meth,
        headers,
        body,
      )
}

let callback = (_conn, req, body) => {
  let uri = req |> Request.uri |> Uri.to_string;
  let meth = req |> Request.meth |> Code.string_of_method;
  let headers = req |> Request.headers |> Header.to_string;
  let body_string = body |> Cohttp_lwt_body.to_string;
  print_request(uri, meth, headers, body_string);
  Server.respond_string(OK, body_string, ());
};

let server = Server.create(`TCP(`Port(8000)), Server.make(callback, ()));

ignore(Lwt_main.run(server));
