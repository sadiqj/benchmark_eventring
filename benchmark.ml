external benchmark_ev_begin_end : int -> unit = "benchmark_ev_begin_end"
external benchmark_ev_counter : int -> unit = "benchmark_ev_counter"
external benchmark_ev_lifecycle : int -> unit = "benchmark_ev_lifecycle"

let run n f iterations =
  let start = Unix.gettimeofday() in
  f iterations;
  let end_ts = Unix.gettimeofday() in
  let duration = end_ts -. start in
  Printf.printf "%s: %2fs for %d iterations = %2fns/span\n" n duration iterations ((1000000000.0 *. duration) /. (float_of_int iterations))

let () =
  let iterations = 1000000000 in
  run "ev_begin_end" (fun i -> benchmark_ev_begin_end i) iterations;
  run "ev_counter" (fun i -> benchmark_ev_counter i) iterations;
  run "ev_lifecycle" (fun i -> benchmark_ev_lifecycle i) iterations