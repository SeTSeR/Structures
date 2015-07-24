module Queue where

import Data.Maybe;

push :: [a] -> a -> [a]
push xs x = xs++[x]

pop :: [a] -> (Maybe a, [a])
pop [] = (Nothing, [])
pop (x:xs) = (Just x, xs)

front :: [a] -> Maybe a
front [] = Nothing
front (x:xs) = Just x

size :: [a] -> Int
size = length

clear :: [a] -> [a]
clear xs = []

exit :: [a] -> Int
exit xs = 0

execute :: (Show a, Eq a, Read a) => [String] -> [a] -> ([a], String, Int)
execute cmd queue =
    case (head cmd) of
        "push" -> ((push queue ((read . head . tail) cmd)), "ok", 1)
        "pop" ->
	    if((fst . pop) queue==Nothing)
	    then
	        ((snd . pop) queue, "error", 1)
	    else
	        ((snd . pop) queue, (show . fromJust . fst . pop) queue, 1)
        "front" ->
	    if(front queue==Nothing)
	    then
	        (queue, "error", 1)
	    else
	        (queue, (show . fromJust . front) queue, 1)
        "size" -> (queue, (show .size) queue, 1)
        "clear" -> (clear queue, "ok", 1)
        "exit" -> (queue, "bye", 0)

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
