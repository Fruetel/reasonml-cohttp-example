/* open Lwt; */
/* open Cohttp; */
/* open Cohttp_lwt_unix; */

/* let print_request = (uri, meth, headers, body) => { */
/*       Printf.sprintf( */
/*         "Uri: %s\nMethod: %s\nHeaders\nHeaders: %s\nBody: %s", */
/*         uri, */
/*         meth, */
/*         headers, */
/*         body, */
/*       ) */
/* } */

/* let callback = (_conn, req, body) => { */
/*   let uri = req |> Request.uri |> Uri.to_string; */
/*   let meth = req |> Request.meth |> Code.string_of_method; */
/*   let headers = req |> Request.headers |> Header.to_string; */
/*   /1* let body_string = Cohttp.Body.to_string(body); *1/ */
/*   /1* print_request(uri, meth, headers, body_string); *1/ */
/*   Server.respond_string(`OK, "here is some body", ()); */
/* }; */

/* let server = Server.create(~mode=`TCP(`Port(8000)), Server.make(callback, ())); */

/* ignore(Lwt_main.run(server)); */

/* let fetch_body = (resp, body) => */

/* let body = */
/*   Client.get(Uri.of_string "https://www.reddit.com/") >>= fun (resp, body) -> */
/*   let code = resp |> Response.status |> Code.code_of_status in */
/*   Printf.printf "Response code: %d\n" code; */
/*   Printf.printf "Headers: %s\n" (resp |> Response.headers |> Header.to_string); */
/*   body |> Cohttp_lwt.Body.to_string >|= fun body -> */
/*   Printf.printf "Body of length: %d\n" (String.length body); */
/*   body */

/* let () = */
/*   let body = Lwt_main.run body in */
/*   print_endline ("Received body\n" ^ body) */

/* let print_body = (resp, body) => { */
/*   Cohttp_lwt.Body.to_string(body) >|= print_endline */
/* } */

/* let fetch = () => { */
/*   Client.get(Uri.of_string("https://www.reddit.com/")) >>= ((resp, body)) */
/*     => { */
/*       Cohttp_lwt.Body.to_string(body) >|= (body) => { */
/*         print_endline(body); */
/*         body; */
/*       } */
/*       body */
/*     } */
/* } */

/* Lwt_main.run(fetch); */

/* */
/* Working from the docs here: https://docs.mirage.io/lwt/Lwt/index.html */
/* */

/* Example 1 */
/* let main = () => { */
/* let line: string = Pervasives.read_line() */
/* print_endline("New unblocked!"); */
/* ignore(line); */
/* } */
/* end of Example 1 */

/* Example 2 */
/* let main = () => { */
/*   let line_promise: Lwt.t(string) = Lwt_io.read_line(Lwt_io.stdin); */
/*   print_endline("Execution just continues..."); */

/*   let line: string = Lwt_main.run(line_promise) */
/*   print_endline("You said: " ++ line); */
/*   ignore(line); */
/* }; */
/* end of Example 2 */

/* Example 3 */
/* let main = () => { */
/*   let p: Lwt.t(unit) = { */
/*     Lwt.bind(Lwt_io.read_line(Lwt_io.stdin), (line1) => { */
/*       Lwt.bind(Lwt_io.read_line(Lwt_io.stdin), (line2) => { */
/*         Lwt_io.printf("%s and %s\n", line1, line2); */
/*       }); */
/*     }); */
/*   } */

/*   Lwt_main.run(p); */
/* }; */
/* end of Example 3 */

/* Example 3 */
/* open Lwt.Infix */
/* let main = () => { */
/*   let p: Lwt.t(unit) = { */
/*     Lwt_io.read_line(Lwt_io.stdin) >>= (line1) => { */
/*       Lwt_io.read_line(Lwt_io.stdin) >>= (line2) => { */
/*         Lwt_io.printf("%s and %s\n", line1, line2); */
/*       } */
/*     } */
/*   } */

/*   Lwt_main.run(p); */
/* }; */
/* end of Example 3 */

/* Example 3 */
/* Requires (preprocess (pps lwt_ppx)) in Dune
   and @opam/lwt_ppx in package.json */
/* open Lwt.Infix */
/* let main = () => { */
/*   let p: Lwt.t(unit) = { */
/*     let%lwt line1 = Lwt_io.read_line(Lwt_io.stdin); */
/*     let%lwt line2 = Lwt_io.read_line(Lwt_io.stdin); */
/*     Lwt_io.printf("%s and %s\n", line1, line2); */
/*   } */

/*   Lwt_main.run(p); */
/* }; */
/* end of Example 3 */

open Lwt;
open Cohttp;
open Cohttp_lwt_unix;

let main = () => {
  let fetch = {
    let url = Uri.of_string("https://reasonml.github.io/");
    Client.get(url)
    >>= (
      ((resp, body)) =>
        Cohttp_lwt.Body.to_string(body)
        >>= (
          body => {
            print_endline(body);
            return(body);
          }
        )
    );
  };

  Lwt_main.run(fetch) |> ignore;
};