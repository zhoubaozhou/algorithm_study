-module(quicksort).
-export([partition/1, sort/1, start/0]).

partition([]) ->
    [];
partition([H|Rest]) ->
    partition(Rest, [], [], H).

partition([], L, R, Priv) ->
    {L, R, Priv};
partition([H|Rest], L, R, Priv) ->
    case H > Priv of
        true -> 
            partition(Rest, L, [H | R], Priv);
        false ->
            partition(Rest, [H | L], R, Priv)
    end.

sort([]) ->
    [];
sort([H|[]]) ->
    [H];
sort(Array) ->
    {L, R, Priv} = partition(Array),
    % 数组 ++ 效率为O(N)，如何优化？
    sort(L) ++ [Priv | sort(R)].

generate_random_array(0, Result) ->
    Result;
generate_random_array(N, Result) when N > 0 ->
    generate_random_array(N-1, [random:uniform() | Result]).

check_sorted_array(Array) ->
    check_sorted_array(Array, 0).

check_sorted_array([], _Prev) ->
    ok;
check_sorted_array([H|Rest], Prev) when Prev =< H ->
    check_sorted_array(Rest, H).

start() ->
    Array = generate_random_array(1000000, []),
    {_, StartSecond, _} = erlang:now(),
    SortedArray = sort(Array),
    {_, EndSecond, _} = erlang:now(),
    check_sorted_array(SortedArray),
    io:format("cost ~p second~n", [EndSecond - StartSecond]).
