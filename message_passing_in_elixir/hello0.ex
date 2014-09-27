defmodule Hello do
  def hello do
    receive do
      {:english, target} ->
        IO.puts "Hello, #{target}."
      {:japanese, target} ->
        IO.puts "こんにちは、#{target}。"
    end
  end
end
