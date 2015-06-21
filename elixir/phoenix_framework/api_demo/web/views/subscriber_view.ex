defmodule ApiDemo.Api.V1.SubscriberView do
  use ApiDemo.Web, :view

  def render("index.json", %{subscribers: subscribers}) do
    format subscribers, []
  end

  def render("show.json", %{subscriber: subscriber}) do
    format [subscriber], []
  end

  defp format([h|t], acc) do
    subscriber = %{
      phone_number: h.phone_number,
      created_at: h.inserted_at,
      updated_at: h.updated_at,
    }
    format(t, acc ++ [subscriber])
  end

  defp format([], acc) do
    acc
  end

end
