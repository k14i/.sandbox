defmodule Hello do
  def hello do
    receive do
      {:english, target} ->
        IO.puts "Hello, #{target}."
        hello
      {:japanese, target} ->
        IO.puts "こんにちは、#{target}。"
        hello
      _ ->
        IO.puts "Huh?"
        hello
    end
  end
end