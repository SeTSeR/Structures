module Stack where

import Data.Maybe;

push :: [a] -> a -> [a]
push xs x = x:xs

pop :: [a] -> (Maybe a, [a])
pop [] = (Nothing, [])
pop (x:xs) = (Just x, xs)

back :: [a] -> Maybe a
back [] = Nothing
back (x:xs) = Just x

size :: [a] -> Int
size = length

clear :: [a] -> [a]
clear xs = []

exit :: [a] -> Int
exit xs = 0

execute :: (Show a, Eq a, Read a) => [String] -> [a] -> ([a], String, Int)
execute cmd stack =
    case (head cmd) of
        "push" -> ((push stack ((read . head . tail) cmd)), "ok", 1)
        "pop" ->
	    if((fst . pop) stack==Nothing)
	    then
	        ((snd . pop) stack, "error", 1)
	    else
	        ((snd . pop) stack, (show . fromJust . fst . pop) stack, 1)
        "back" ->
	    if(back stack==Nothing)
	    then
	        (stack, "error", 1)
	    else
	        (stack, (show . fromJust . back) stack, 1)
        "size" -> (stack, (show .size) stack, 1)
        "clear" -> (clear stack, "ok", 1)
        "exit" -> (stack, "bye", 0)

getAndExecuteCommand :: (Show a, Eq a, Read a) => [a] -> IO ()
getAndExecuteCommand xs = do
    command <- getLine
    printSecond (result command)
    if(getThird (result command)==1)
    then (getAndExecuteCommand . getFirst) (result command)
    else return ()
    where
        printSecond = putStrLn . getSecond
	getFirst (a, b, c) = a
	getSecond (a, b, c) = b
	getThird (a, b, c) = c
	result command = execute (words command) xs

nullIntList :: Int -> [Int]
nullIntList arg = []

main :: IO ()
main = (getAndExecuteCommand . nullIntList) 0
