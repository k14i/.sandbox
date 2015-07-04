defmodule ApiDemo.Api.V1.SubscriberView do
  use ApiDemo.Web, :view

  def render("index.json", %{subscribers: subscribers}) when is_list(subscribers) do
    format subscribers, []
  end

  def render("show.json", %{subscriber: subscriber}) when is_list(subscriber) do
    format subscriber, []
  end

  def render("show.json", %{subscriber: subscriber}) when is_list(subscriber) == false do
    format [subscriber], []  # Use when `Repo.get_by! Subscriber, phone_number: phone_number`
  end

  defp format [h|t], acc do
    subscriber = %{
      phone_number: h.phone_number,
      sim_id: h.sim_id,
      status: h.status,
      created_at: h.inserted_at,
      updated_at: h.updated_at,
    }
    format t, acc ++ [subscriber]
  end

  defp format [], acc do
    acc
  end

end
