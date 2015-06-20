defmodule ApiDemo.Api.V1.SubscriberView do
  use ApiDemo.Web, :view

  def render("index.json", %{subscribers: subscribers}) do
    #subscribers
    format(%{subscribers: subscribers})
  end

  def render("show.json", %{subscriber: subscriber}) do
    format(%{subscriber: subscriber})
  end

  defp format_subscribers([h|t], acc) do
    subscriber = %{
      phone_number: h.phone_number,
      created_at: h.inserted_at,
      updated_at: h.updated_at,
    }
    format_subscribers(t, acc ++ [subscriber])
  end

  defp format_subscribers([], acc) do
    acc
  end

  defp format(%{subscribers: subscribers}) do
    format_subscribers(subscribers, [])
  end

  defp format(%{subscriber: subscriber}) do
    [
      %{
        phone_number: subscriber.phone_number,
        created_at: subscriber.inserted_at,
        updated_at: subscriber.updated_at,
      }
    ]
  end

end
