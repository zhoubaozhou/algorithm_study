-module(quicksort).
-export([partition/1, sort/1, start/0]).

partition([]) ->
    [];
partition([H|Rest]) ->
    partition(Rest, [], [], H).

partition([], L, R, Pivot) ->
    {L, R, Pivot};
partition([H|Rest], L, R, Pivot) ->
    case H > Pivot of
        true -> 
            partition(Rest, L, [H | R], Pivot);
        false ->
            partition(Rest, [H | L], R, Pivot)
    end.

sort([]) ->
    [];
sort([H|[]]) ->
    [H];
sort(Array) ->
    {L, R, Pivot} = partition(Array),
    % 数组 ++ 效率为O(N)，如何优化？
    sort(L) ++ [Pivot | sort(R)].

%% simplest version
qsort1([]) ->
    [];
qsort1([Pivot|Rest]) ->
    qsort1([X || X <- Rest , X =< Pivot])
    ++ [Pivot] ++
    qsort1([X || X <- Rest, X > Pivot]).

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

test_quicksort(Array, QsortFun) ->
    {_, StartSecond, _} = erlang:now(),
    SortedArray = QsortFun(Array),
    {_, EndSecond, _} = erlang:now(),
    check_sorted_array(SortedArray),
    io:format("cost ~p second~n", [EndSecond - StartSecond]).

start() ->
    Array = generate_random_array(1000000, []),
    %% 测试结果, qsort1速度约为sort版本的2/3
    %% sort版本就需要partition一次，qsort1需要两次，但是没有详细数据支持这个猜测。
    test_quicksort(Array, fun(X) -> sort(X) end),
    test_quicksort(Array, fun(X) -> qsort1(X) end).
